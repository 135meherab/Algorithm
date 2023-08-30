th;
    pair<int,int> curr = {di,dj};

    while (!(curr.first == si && curr.second == sj))
    {
        path.push_back(curr);
        curr = parent[curr.first][curr.second];
    }
    path.push_back({si,sj});
    reverse(path.begin(),path.end());

    if(visited[di][dj])
    {
        for (int i = 1; i <= path.size()-1; i++)
        {
            if(path[i-1].first== path[i].first)
            {
                if(path[i-1].second == path[i].second+1)
                {
                    cout<<"L";
                }
                else cout<<"R";
            }
            else
            {
                if(path[i-1].first == path[i].first+1)
                {
                    cout<<"U";
                }
                else cout<<"D";
            }
        }
    }
    else cout<<"-1";