#include <bits/stdc++.h>
using namespace std;

string SelectFile (int n)
{
    switch(n)
    {
        case 1 : return "a_example";
        case 2 : return "b_little_bit_of_everything.in";
        case 3 : return "c_many_ingredients.in";
        case 4 : return "d_many_pizzas.in";
        case 5 : return "e_many_teams.in";
        default : return "";
    }    
}

vector<pair<int,vector<string> > > ReadInputFile (string s)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream file(s);
    if (!file.is_open()) {
        return vector<pair<int, vector<string> > >();
    }
    int header[4];
    string line;
    int i = 0,N;
    

    getline(file, line);
    stringstream head(line);
    while(head>>N)
        header[i++] = N;

    vector<pair<int,vector<string> > > pizzas(N);

    i=0;
    while (getline(file, line)) {
        int temp;
        string s_temp;
        vector<string> v_temp;
        stringstream input(line);
        input >> temp;
        pizzas[i] = make_pair(temp,v_temp);

        while(input >> s_temp)
            pizzas[i].second.push_back(s_temp);
        i++;    
    }
    file.close();
    return pizzas;
} 

int main()
{
   int n;
   cout<<"Select file : "<<endl;
   cin>>n;

   vector<pair<int,vector<string> > > pizzas = ReadInputFile(SelectFile(n));
}
