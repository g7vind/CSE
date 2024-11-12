#include<stdio.h>
#include<stdbool.h>
#define max_states 100
#define epsilon 'e'

int nfa[max_states][max_states]={0};
bool closure[max_states][max_states]={0};
bool state_used[max_states]={0};

void find_closure(int state, int num_states) {
    closure[state][state]=true;
    for(int i=0;i<num_states;i++){
    	if(nfa[state][i] && !closure[state][i]){
    		closure[state][i] = true;
    		find_closure(i,num_states);
    		for(int j=0;j<num_states;j++){
    			if(closure[i][j]){
    				closure[state][j]=true;
    			}
    		}
    	}
    }
}

void main(){
    int from_state, to_state;
    char symbol;
    int num_states = 0;
    printf("Enter the transitions (from_state, symbol, to_state) (Enter -1 to stop): ");
    while(1) {
        scanf("%d", &from_state);
        if(from_state == -1) break;
        scanf(" %c %d", &symbol, &to_state);
        if(symbol == epsilon) nfa[from_state][to_state] = 1;
        state_used[from_state] = state_used[to_state] = 1;
        num_states = num_states > from_state ? num_states : from_state+1;
        num_states = num_states > to_state ? num_states : to_state+1;
    }
    for(int i = 0; i <= num_states; i++) {
        if(state_used[i]) {
            find_closure(i,num_states);
        }
    }
    for(int i = 0; i <= num_states; i++) {
        if(state_used[i]) {
            for(int j = 0; j <= num_states; j++) {
                if(state_used[j] && closure[i][j]) 
                    printf("q%d ",j);
            }
            printf("\n");
        }
    }

}