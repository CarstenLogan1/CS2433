#include <cstdlib>
#include <iostream>
#include <cstring>

using namespace std;

char* setName(){
    char* name = new char[30];
    bool valid;
    
    do{
        flag:
        valid = false;
        cout<<"Enter a name in lowercase only: ";
        scanf("%s", name);
        
        for(int i = 0; i < strlen(name); i++){
            if(name[i] < 'a' || name[i] > 'z'){
                goto flag;
            }
            
        }
    } while(valid);
    return name;
}

char* setBadge(){
    char* badge = new char[30];
    bool valid;
    do{
        flag:
        valid = false;
        cout<<"Enter a badge number please, only digits: ";
        scanf("%s", badge);
        
        for(int i = 0; i < strlen(badge); i++){
            if(badge[i] < '0' || badge[i] > '9'){
                goto flag;
            }
        }
    } while(valid);
        return badge;
}

char* setComp(){
    char* comp = new char[30];
    bool valid;
    do{
        flag:
        valid = false;
        cout<<"Enter a company please, only uppercase letters: ";
        scanf("%s", comp);
        
        for(int i = 0; i < strlen(comp); i++){
            if(comp[i] < 'A' || comp[i] > 'Z'){
                goto flag;
            }
        }
    } while(valid);
        return comp;
}

int main(int argc, char** argv) {
    char* name = setName();
    char* badge = setBadge();
    char* comp = setComp();
    
    char email[30];
    strcpy(email, name);
    strcat(email, ".");
    strcat(email, badge);
    strcat(email, "@");
    strcat(email, comp);
    strcat(email, ".edu");
    
    char* ptr = strrchr(email, '.');
    ptr++;
    while(*ptr != '\0'){
        *ptr -= 32;
        ptr++;
    }
    int cmp = strcmp(ptr, ".EDU");
    
    printf("%s\n", email);
    
    return 0;
}
