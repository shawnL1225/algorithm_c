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
    int flag_order_by = 0;
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
        for(int condition_i=0;;condition_i++)
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
                if(sql_each[sql_ct].where_clause.conditions[condition_i].optr == "LIKE"){
                    tok.erase(tok.begin()+tok.length()-1);
                    tok.erase(tok.begin());
                }
                sql_each[sql_ct].where_clause.conditions[condition_i].value = tok;
                break;
            }
            if(sql_each[sql_ct].where_clause.conditions[condition_i].optr == "LIKE"){
                tok.erase(tok.begin()+tok.length()-1);
                tok.erase(tok.begin());
            }
            sql_each[sql_ct].where_clause.conditions[condition_i].value = tok;

            ss >> tok;
            if(tok == "ORDER")
            {
                break;
            }
            if(tok == "AND")
                sql_each[sql_ct].where_clause.type_of_connector = 1;           
        }
    }
    if(tok == "ORDER")
    {
        ss >> tok; // BY
        ss >> tok;
        sql_each[sql_ct].order_by_col = tok;
        sql_each[sql_ct].flag_order_by = 1;
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
bool is_exist[302];

bool final_cs[302];
void exe_condition(){
    memset(final_cs,1,sizeof(final_cs));

    bool condition_result[302][1000];
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
        else if(sql_each[sql_ct].where_clause.conditions[condition_i].optr == "LIKE")
        {
            for(int std_i=0; std_i<n; std_i++)
            {
                string s = sql_each[sql_ct].where_clause.conditions[condition_i].value;
                string tableS = tableA[std_i][mapStudent[sql_each[sql_ct].where_clause.conditions[condition_i].column]];
                int len = s.length();
                int tlen = tableS.length();
                for(int tablei=0, fi=0; fi<len && tablei<tlen; )
                {
                    // cout << fi <<endl;
                    // cout << tablei <<endl;
                    if(s[fi] == '%'){
                        int iter = fi+1;
                        while(s[iter] != '%' && iter<len) iter++;
                        int substr_len = iter - (fi+1);
                        if(substr_len)
                        {
                            string substr = s.substr(fi+1,substr_len);
                            // cout << substr <<endl;
                            tablei = tableS.find(substr,tablei);
                            if(tablei>=0)
                            {
                                fi += substr_len+1 ;
                                tablei += substr_len;
                            }
                            else
                                break;
                        }
                        else{ // finish
                            condition_result[std_i][condition_i] = 1;
                            break;
                        }
                    }
                    // else if(s[fi] == '_'){
                    //     if(tablei<tableS.length())
                    //     {
                    //         tablei++;
                    //         fi++;
                    //     }
                    //     else
                    //         break;
                    // }
                    else{
                        if(tableS[tablei] == s[fi])
                        {
                            tablei++;
                            fi++;
                        }
                        else
                            break;
                    }

                    if(tablei == tableS.length() && fi+1 >= s.length())
                        condition_result[std_i][condition_i] = 1;
                    
                }
                    
                
            }
            
        }
    }

    //AND OR compute   
    if(sql_each[sql_ct].where_clause.num_of_conditions > 0)
    {
        if(sql_each[sql_ct].where_clause.type_of_connector == 1)
        {
            for(int j=0; j<sql_each[sql_ct].where_clause.num_of_conditions; j++)
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

    //  for(int i=0;i<n;i++)
    //     cout << final_cs[i] << ' ';
    // cout << endl;
    

}

struct Sort{
    string s;
    int id;
};

bool isnum = 1;
bool comp(Sort a, Sort b){

    if(sql_each[sql_ct].flag_inc == 0){
        if(isnum){
            int num_a = atoi(a.s.c_str());
            int num_b = atoi(a.s.c_str());
            return num_a < num_b;
        }
        else{
            return a.s < b.s;
        }
    }
    else{
        if(isnum){
            int num_a = atoi(a.s.c_str());
            int num_b = atoi(a.s.c_str());
            return num_a > num_b;
        }
        else{
            return a.s > b.s;
        }
    }
}

void sel_execute(){
    exe_condition();

    Sort sortInd[n];
    for(int i=0;i<n;i++){
        sortInd[i].s = tableA[i][mapStudent[sql_each[sql_ct].order_by_col]];
        sortInd[i].id = i;
    }
    if(sql_each[sql_ct].flag_order_by == 1)
    {
        isnum = 1;
        for(int i=0;i<sortInd[0].s.length();i++){
            if(!isdigit(sortInd[0].s[i])) isnum = 0;
        }
        sort(sortInd,sortInd+n,comp); 
    }

    for(int std_i=0; std_i<n;std_i++)
    {
        int choose_i = sortInd[std_i].id;
        if(final_cs[choose_i] && is_exist[choose_i])
        {
            for(int selected_i=0; selected_i < sql_each[sql_ct].col_list.length_of_cols; selected_i++)
            {
                if(sql_each[sql_ct].col_list.cols[selected_i] == "*")
                {
                    for(int i=0;i<6;i++)
                    {
                        cout << tableA[choose_i][i] << ' ';
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
        for(int condition_i=0;;condition_i++)
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
                if(sql_each[sql_ct].where_clause.conditions[condition_i].optr == "LIKE"){
                    tok.erase(tok.begin()+tok.length()-1);
                    tok.erase(tok.begin());
                }
                sql_each[sql_ct].where_clause.conditions[condition_i].value = tok;
                break;
            }
            if(sql_each[sql_ct].where_clause.conditions[condition_i].optr == "LIKE"){
                tok.erase(tok.begin()+tok.length()-1);
                tok.erase(tok.begin());
            }
            sql_each[sql_ct].where_clause.conditions[condition_i].value = tok;

            ss >> tok;
            if(tok == "AND")
                sql_each[sql_ct].where_clause.type_of_connector = 1;
            
        }
    }
}

void del_execute(){
    exe_condition();
    for(int del_i=0; del_i<n;del_i++)
    {
        if(final_cs[del_i] && is_exist[del_i])
        {
            is_exist[del_i] = 0;
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
            sel_execute();
        }
        else if(tok == "DELETE"){
            del_input();
            del_execute();
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
    memset(is_exist,1,sizeof(is_exist));
    input();
}