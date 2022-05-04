#include <iostream>
#include <cstring>
#include <queue>
#include <list>
using namespace std;

char map[] = "22233344115566070778889990";
char callnum[101];
char words[50000][51];
char nums[50000][51];
char lens[50000];

char input[300*1024];

struct node_t {
    node_t(): off(0), count(0) {}
    uint8_t off;
    uint8_t count;
    uint16_t seqs[100];
};

int trans(char from[], char to[]) 
{
    int i = 0;
    while (from[i] != 0) {
        to[i] = map[from[i] - 'a'];
        i++;
    }
    to[i] = 0;
    return i;
}

node_t bfs(queue<node_t> &queue, int wn, int call_len) {
    node_t ret;
    while (queue.size()) {
        node_t &front = queue.front();
        // printf("++++%d\n", front.off);
        for (int i = 0; i < wn; i++) {
            // printf("----%s\n", nums[i]);
            int len = lens[i];
            if (front.off + len > call_len) {
                continue;
            } 
            int cmp = strncmp(callnum + front.off, nums[i], len);
            if (cmp != 0) {
                continue;
            }

            node_t node = front;
            node.seqs[node.count] = i;
            node.count++;
            if (node.off + len == call_len) {
                return node;
            }
            node.off += len; 
            queue.push(node);
        }
        queue.pop();
    }
    return ret;
}


int main()
{
    int n;
    while (scanf("%s", callnum)) {
        if (callnum[0] == '-') {
            return 0;
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", words[i]);
            lens[i] = trans(words[i], nums[i]);
            //printf("%s\n", nums[i]);
        }
        queue<node_t> queue;
        queue.push(node_t());
        node_t node = bfs(queue, n, strlen(callnum));
        if (!node.count) {
            printf("No solution.\n");
        } else {
            for (uint8_t i = 0; i < node.count; ++i) {
                if (i == node.count - 1) {
                    printf("%s\n", words[node.seqs[i]]);
                } else {
                    printf("%s ", words[node.seqs[i]]);
                }
            }
        }
    }
    return 0;
}

