/*
71. Simplify Path
Medium

Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.

Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

Example 4:

Input: "/a/./b/../../c/"
Output: "/c"

Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"

Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
*/

// Using a deque since for ".." we need to pop from the back. (queue usually pops from front)
// We could even use a stack but the words/path would be in reverse order
class Solution {
public:
    string simplifyPath(string path) {
        deque<string> s;
        string temp="";
        int ind=0;
        string result="";
        
        //replacing extra //// (any number of /'s)  with a single /
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='/')
            {
                int idx=i+1;
                while(1)
                {
                    if(path[idx]!='/')
                        break;
                    idx++;
                }
                path.erase(i+1,idx-i-1);
            }
        }

        cout<<path<<endl;
    for(int i=1;i<path.size();i++)
    {
        if(path[i]!='/')
        temp+=path[i];
        if(path[i]=='/' || i==path.size()-1)
        {
            cout<<temp<<"\n";
            if(temp=="..")
            {
                if(!s.empty())
                s.pop_back();
                
            }  
            else if(temp==".")
                temp.erase();
            
            else
                s.push_back(temp);
            temp.erase();
        }
        
    }
        result+="/";
    
        while(!s.empty())
        {
            result+=s.front();
            s.pop_front();
            if(!s.empty())
            result+="/";
        }
        return result;
    }
};