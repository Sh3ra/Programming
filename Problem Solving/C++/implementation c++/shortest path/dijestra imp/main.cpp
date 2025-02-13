#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > edgeList[100005];
long long shortPath[100005];
int prevNode[100005];
void printPath(int n){
if(n==1 ){;
cout<<n<<" ";
    return;
}
printPath(prevNode[n]);
cout<<n<<" ";
return;
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 0;i < m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        edgeList[u].push_back(make_pair(v,w));
        edgeList[v].push_back(make_pair(u,w));
    }
    for(int i = 1;i <= 100000;i++)
        shortPath[i] = 1e13;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > myQ;
    shortPath[1] = 0;
    myQ.push(make_pair(0,1));
    while(!myQ.empty())
    {
        int source = myQ.top().second;
        myQ.pop();
        for(int i = 0;i < edgeList[source].size();i++)
        {
            if(shortPath[edgeList[source][i].first] > shortPath[source] + edgeList[source][i].second)
            {
                shortPath[edgeList[source][i].first] = shortPath[source] + edgeList[source][i].second;
                myQ.push(make_pair(shortPath[edgeList[source][i].first],edgeList[source][i].first));
                prevNode[edgeList[source][i].first] = source;
            }
        }
    }
    if(shortPath[n] == 1e13)
    {
        cout << "-1";
        return 0;
    }
    printPath(n);

    return 0;
}
