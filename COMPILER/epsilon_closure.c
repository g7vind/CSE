#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>

#define MAX_STATES 100
#define EPSILON 'e'

int nfa[MAX_STATES][MAX_STATES] = {0};
int closure[MAX_STATES][MAX_STATES] = {0};
int state_used[MAX_STATES] = {0};

void find_closure(int state,int num_state){
    closure[state][state]=1;
    for(int i=0;i<num_state;i++){
        if(nfa[state][i] && !closure[state][i]){
            closure[state][i]=1;
            find_closure(i,num_state);
            for(int j=0;j<num_state;j++){
                if(closure[i][j]){
                    closure[state][j]=1;
                }
            }
        }
    }
}

void main(){
    int from_state,to_state;
    char symbol;
    int num_states=0;
    printf("Enter transitions (format: state1 symbol state2)[eg : 0 1 0]. Enter 'done' to finish:\n");
    while(scanf("%d %c %d",&from_state,&symbol,&to_state)==3){
        if(symbol==EPSILON){
            nfa[from_state][to_state]=1;
        }
        state_used[from_state]=1;
        state_used[to_state]=1;
        if(from_state>=num_states) num_states=from_state+1;
        if(to_state>=num_states) num_states=to_state+1;
    }
    for(int i=0;i<num_states;i++){
        if(state_used[i]){
            find_closure(i,num_states);
        }
    }
    for(int i=0;i<num_states;i++){
        if(state_used[i]){
            printf("Epsilon closure of state q%d: ",i);
            for(int j=0;j<num_states;j++){
                if(closure[i][j]){
                    printf("q%d ",j);
                }
            }
            printf("\n");
        }
    }
}