
#include <windows.h>
#include <stdio.h>

#define USN_VOL_LEN 16
#define USN_CJ_MAJOR_VERSION_EXPECTED       2
#define USN_CJ_MINOR_VERSION_EXPECTED       0
#define USN_CJ_SIZEOF_USN_RECORD_EXPECTED   64

static HANDLE gs_hcj = INVALID_HANDLE_VALUE;

int usn_opencj(char vol)
{
    DWORD errcode = 0;
    if (!((vol >= 'a' && vol <= 'z') ||
        (vol >= 'A' && vol <= 'Z')))
    {
        return -1;
    }

    char buf[USN_VOL_LEN];
    gs_hcj = INVALID_HANDLE_VALUE;
    sprintf(buf, "\\\\.\\%c:", vol);

    gs_hcj = CreateFileA(buf, GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL, OPEN_EXISTING, 0, NULL);

    if (INVALID_HANDLE_VALUE == gs_hcj)
    {
        errcode = GetLastError();
        return -1;
    }
    return 0;
}


int usn_querystat()
{
    BOOL flag = FALSE;
    LPVOID pbuf = NULL;
    if (sizeof(USN_RECORD) != 
        USN_CJ_SIZEOF_USN_RECORD_EXPECTED)
    {
        return -1;
    }

    DWORD bytes;
    USN_JOURNAL_DATA ujd;
    flag = DeviceIoControl (gs_hcj, FSCTL_QUERY_USN_JOURNAL,
        NULL, 0, &ujd, sizeof(USN_JOURNAL_DATA), &bytes, NULL);
    if (!flag)
    {
        return -1;
    }

    READ_USN_JOURNAL_DATA rujd;
    rujd.StartUsn = 0;
    rujd.ReasonMask = USN_REASON_FILE_CREATE | USN_REASON_FILE_DELETE;
    rujd.ReturnOnlyOnClose = 0;
    rujd.Timeout = -100000000;
    rujd.BytesToWaitFor = 0;
    rujd.UsnJournalID = ujd.UsnJournalID;

    BYTE buf[USN_PAGE_SIZE];
    USN_RECORD *pr;
    flag = DeviceIoControl(gs_hcj, FSCTL_READ_USN_JOURNAL, &rujd,
        sizeof(rujd), buf, sizeof(buf), &bytes, NULL);
    if (!flag)
    {
        return -1;
    }
    pr = (USN_RECORD *)(buf + sizeof(USN));
    while((DWORD)pr < (DWORD)(buf + bytes))
    {
        printf("r: sun = %lld, rlen = %d, flen = %d, fo = %d\n",
            pr->Usn, pr->RecordLength, pr->FileNameLength, pr->FileNameOffset);
        pr = (USN_RECORD *)(((PBYTE)pr) + pr->RecordLength);
    }

    return 0;
}

void usn_test(void)
{
    int ret = 0;
    ret = usn_opencj('d');
    ret = usn_querystat();
}

