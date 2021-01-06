#include <bits/stdc++.h>
using namespace std;

map<string, int> mapStudent;
int n,m;
string command,tok;
stringstream ss;
string tableA[302][6];

struct condition
{
    string column;    // column
    string optr;    // optr
    string value;    // value
};

struct COLUMN_LIST
{
    int length_of_cols;
    string cols[100];
};

struct WHERE_CLAUSE
{
    int num_of_conditions = 0;
    struct condition conditions[1000];
    int type_of_connector = 0;  // 1 for AND;  0 for OR
};


struct SQL
{
    // column list
    struct COLUMN_LIST col_list;

    // where clause
    struct WHERE_CLAUSE where_clause;

    // order by
    int flag_order_by;
    string order_by_col;
    int flag_inc = 0;   // 0 for ASC;  1 for DES
};
SQL sql_each[30];
int sql_ct = 0;
void sel_input(){
    int i=0;
    while(ss >> tok)
    {
        if(tok == "FROM") break;
        if(tok[tok.length()-1] == ',')
            tok.erase(tok.begin()+tok.length()-1);
        
        sql_each[sql_ct].col_list.cols[i] = tok;
        
        i++;
    }
    sql_each[sql_ct].col_list.length_of_cols = i;
    if(tok == "FROM")
    {
        ss >> tok; // tableA
        ss >> tok; // get next
    }
    if(tok == "WHERE")   
    {
        for(int condition_i=0;condition_i<2;condition_i++)
        {
            sql_each[sql_ct].where_clause.num_of_conditions++;
            ss >> tok;
            sql_each[sql_ct].where_clause.conditions[condition_i].column = tok;
            ss >> tok;
            sql_each[sql_ct].where_clause.conditions[condition_i].optr = tok;
            ss >> tok;
            if(tok[tok.length()-1] == ';')
            {
                tok.erase(tok.begin()+tok.length()-1);
                sql_each[sql_ct].where_clause.conditions[condition_i].value = tok;
                break;
            }
            sql_each[sql_ct].where_clause.conditions[condition_i].value = tok;

            ss >> tok;
            if(tok == "ORDER")
            {
                break;
            }
            if(tok == "AND")
                sql_each[sql_ct].where_clause.type_of_connector = 1;
            else
                sql_each[sql_ct].where_clause.type_of_connector = 0;
        }
        
    }
    if(tok == "ORDER")
    {
        ss >> tok; // BY
        ss >> tok;
        sql_each[sql_ct].order_by_col = tok;
        if(tok[tok.length()-1] == ';')
        {
            tok.erase(tok.begin()+tok.length()-1);
            sql_each[sql_ct].order_by_col = tok;
            
        }
        else
        {
            sql_each[sql_ct].order_by_col = tok;
            ss >> tok;
            if(tok == "DESC;")
                sql_each[sql_ct].flag_inc = 1;
        }
    }
    
}

bool final_cs[301];
void exe_condition(){
    memset(final_cs,1,sizeof(final_cs));

    bool condition_result[300][1000];
    memset(condition_result,0,sizeof(condition_result));
    
    for(int condition_i=0; condition_i < sql_each[sql_ct].where_clause.num_of_conditions; condition_i++)
    {
        if(sql_each[sql_ct].where_clause.conditions[condition_i].optr == "=")
        {
            for(int std_i=0; std_i<n; std_i++)
            {
                if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]] == sql_each[sql_ct].where_clause.conditions[condition_i].value)
                    condition_result[std_i][condition_i] = 1;
            }
        }
        else if(sql_each[sql_ct].where_clause.conditions[condition_i].optr == ">")
        {
            for(int std_i=0; std_i<n; std_i++)
            {
                if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]].length() >  sql_each[sql_ct].where_clause.conditions[condition_i].value.length())
                    condition_result[std_i][condition_i] = 1;
                else if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]].length() <  sql_each[sql_ct].where_clause.conditions[condition_i].value.length())
                    continue;
                if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]] > sql_each[sql_ct].where_clause.conditions[condition_i].value)
                    condition_result[std_i][condition_i] = 1;
            }
        }
        else if(sql_each[sql_ct].where_clause.conditions[condition_i].optr == "<")
        {
            for(int std_i=0; std_i<n; std_i++)
            {
                if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]].length() <  sql_each[sql_ct].where_clause.conditions[condition_i].value.length())
                    condition_result[std_i][condition_i] = 1;
                else if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]].length() >  sql_each[sql_ct].where_clause.conditions[condition_i].value.length())
                    continue;
                if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]] < sql_each[sql_ct].where_clause.conditions[condition_i].value)
                    condition_result[std_i][condition_i] = 1;
            }
        }
        else if(sql_each[sql_ct].where_clause.conditions[condition_i].optr == ">=")
        {
            for(int std_i=0; std_i<n; std_i++)
            {
                if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]].length() >  sql_each[sql_ct].where_clause.conditions[condition_i].value.length())
                    condition_result[std_i][condition_i] = 1;
                else if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]].length() <  sql_each[sql_ct].where_clause.conditions[condition_i].value.length())
                    continue;
                if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]] >= sql_each[sql_ct].where_clause.conditions[condition_i].value)
                    condition_result[std_i][condition_i] = 1;
            }
        }
        else if(sql_each[sql_ct].where_clause.conditions[condition_i].optr == "<=")
        {
            for(int std_i=0; std_i<n; std_i++)
            {
                if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]].length() <  sql_each[sql_ct].where_clause.conditions[condition_i].value.length())
                    condition_result[std_i][condition_i] = 1;
                else if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]].length() >  sql_each[sql_ct].where_clause.conditions[condition_i].value.length())
                    continue;
                if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]] <= sql_each[sql_ct].where_clause.conditions[condition_i].value)
                    condition_result[std_i][condition_i] = 1;
            }
        }
        else if(sql_each[sql_ct].where_clause.conditions[condition_i].optr == "!=")
        {
            for(int std_i=0; std_i<n; std_i++)
            {
                if(tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]] != sql_each[sql_ct].where_clause.conditions[condition_i].value)
                    condition_result[std_i][condition_i] = 1;
            }
        }
    }
    

    // for(int i=0;i<n;i++)
    //     cout << condition_result[i][0] << ' ';
    // cout << endl;
    //  for(int i=0;i<n;i++)
    //     cout << condition_result[i][1] << ' ';
    // cout << endl;

    //AND OR compute
    
    if(sql_each[sql_ct].where_clause.num_of_conditions > 0)
    {
        if(sql_each[sql_ct].where_clause.type_of_connector == 1)
        {
            for(int j=0; j<sql_each[sql_ct].where_clause.num_of_conditions ;j++)
            {
                for(int i=0;i<n;i++)
                    final_cs[i] = final_cs[i] && condition_result[i][j];
            }
            
        }
        else
        {
            memset(final_cs,0,sizeof(final_cs));
            for(int j=0; j<sql_each[sql_ct].where_clause.num_of_conditions ;j++)
            {
                for(int i=0;i<n;i++)
                    final_cs[i] = final_cs[i] || condition_result[i][j];
            }
        }
    }
}

bool comp(string s1[6],string s2[6])
{
    if(sql_each[sql_ct].flag_inc == 0)  
        return s1[mapStudent[sql_each[sql_ct].order_by_col]] < s2[mapStudent[sql_each[sql_ct].order_by_col]];
    else
        return s1[mapStudent[sql_each[sql_ct].order_by_col]] > s2[mapStudent[sql_each[sql_ct].order_by_col]];
}

void execute_sel(){
    exe_condition();
    
    //origin output

    // string orderTable[300][6];
    // for(int std_i=0; std_i<n; std_i++)
    //     for(int std_j=0; std_j<6;std_j++)
    //         orderTable[std_i][std_j] = tableA[std_i][std_j];

    // sort(orderTable,orderTable+n,comp);

    // for(int std_i=0; std_i<n; std_i++)
    // {
    //     for(int std_j=0; std_j<6;std_j++)
    //     {
    //         cout << orderTable[std_i][std_j] << ' ';
    //     }
    //     cout << endl;
    // }

    for(int std_i=0; std_i<n;std_i++)
    {
        if(final_cs[std_i])
        {
            for(int selected_i=0; selected_i < sql_each[sql_ct].col_list.length_of_cols; selected_i++)
            {
                if(sql_each[sql_ct].col_list.cols[selected_i] == "*")
                {
                    for(int i=0;i<6;i++)
                    {
                        cout << tableA[std_i][i] << ' ';
                    }
                }
                else
                {
                    cout << tableA[std_i][mapStudent[sql_each[sql_ct].col_list.cols[selected_i]]] << ' ';
                }
            }
            cout << endl;
        }
    }

}

void del_input(){
    ss >> tok;  //from
    ss >> tok;  //tableA
    if(tok[tok.length()-1] !=';')
    {
        ss >> tok; //where
        for(int condition_i=0;condition_i<2;condition_i++)
        {
            sql_each[sql_ct].where_clause.num_of_conditions++;
            ss >> tok;
            sql_each[sql_ct].where_clause.conditions[condition_i].column = tok;
            ss >> tok;
            sql_each[sql_ct].where_clause.conditions[condition_i].optr = tok;
            ss >> tok;
            if(tok[tok.length()-1] == ';')
            {
                tok.erase(tok.begin()+tok.length()-1);
                sql_each[sql_ct].where_clause.conditions[condition_i].value = tok;
                break;
            }
            sql_each[sql_ct].where_clause.conditions[condition_i].value = tok;

            ss >> tok;
            if(tok == "AND")
                sql_each[sql_ct].where_clause.type_of_connector = 1;
            else
                sql_each[sql_ct].where_clause.type_of_connector = 0;
        }
    }
}

void execute_del(){
    exe_condition();
    for(int del_i=0; del_i<n;del_i++)
    {
        if(final_cs[del_i])
        {
            for(int i=0;i<6;i++)
                tableA[del_i][i] = "";
        }
    }
}

void input()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> tableA[i][0] >> tableA[i][1] >> tableA[i][2] >> tableA[i][3] >> tableA[i][4] >> tableA[i][5];
    }
    cin.ignore();
    for(int i=0;i<m;i++,sql_ct++)
    {
        getline(cin,command);
        ss.clear();
        ss.str("");
        ss << command;
        
        
        ss >> tok;
        if(tok == "SELECT"){
            sel_input();
            execute_sel();
        }
        else if(tok == "DELETE"){
            del_input();
            execute_del();
        }

        
        
    }
}
int main(){
    mapStudent["ID"] = 0;
    mapStudent["Name"] = 1;
    mapStudent["StudentID"] = 2;
    mapStudent["Class"] = 3;
    mapStudent["Email"] = 4;
    mapStudent["Phone"] = 5;
    input();
}