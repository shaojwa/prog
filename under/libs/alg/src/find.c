

 __declspec(dllexport) int find_single(int arr[], int count)
{
    int ans = 0;
    int i = 0;
    for (i = 0; i < count; i++)
    {
        ans ^= arr[i];
    }
    return ans;
}