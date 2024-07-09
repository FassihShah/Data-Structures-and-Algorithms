int toyCollection(int* children, int* toys, int n)
{
    int cnt = 0;
    Queue<int> childs(n);
    for (int i = 0; i < n; i++)
    {
        childs.enQueue(children[i]);
    }
    int i = 0;
    while (!childs.isEmpty() && i < n)
    {
        int c = childs.deQueue();
        if (toys[i] != c)
            childs.enQueue(c);
        else
        {
            i++;
            cnt++;
        }
    }
    return cnt;
}