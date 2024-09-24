class Solution {
public:
    class x{
        public:
        x* vec[10];
        x(){
            for(int i=0;i<10;i++) vec[i]=NULL;
        }
    };
    class node{
        public:
        x* root;
        node(){
            root=new x();
        }
        void add(string temp){
            // cout<<temp<<endl;
            x* yyy=root;
            for(int i=0;i<temp.length();i++){
                int t=temp[i]-'0';
                if((yyy->vec[t])==NULL){
                    yyy->vec[t]=new x();
                }
                yyy=yyy->vec[t];
            }
        }
        int length(string temp){
            // cout<<temp<<endl;
            x* yyy=root;
            int count=0;
            for(int i=0;i<temp.length();i++){
                int t=temp[i]-'0';
                if(yyy->vec[t]==NULL){
                    break;
                }
                else{
                   yyy=yyy->vec[t];
                   count++;
                }
            }
            return count;
        }
    };
    // string to_string(int temp){
    //     string ans;
    //     while(temp!=0){
    //         ans+=to_string
    //     }
    // }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        node* ans=new node();
        for(int i=0;i<arr1.size();i++){
            string y=to_string(arr1[i]);
            ans->add(y);
        }

        int count=0;
        for(int i=0;i<arr2.size();i++){
            string y=to_string(arr2[i]);
            
            count=max(count,ans->length(y));
        }
        return count;
    }
};