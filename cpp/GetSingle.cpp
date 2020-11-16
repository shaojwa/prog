

int GetSingle(int arr[], int count)
{
    int ans = 0;
    for(int i = 0; i < count; i++)
    {
        ans ^= arr[i];
    }
    return ans;
}
