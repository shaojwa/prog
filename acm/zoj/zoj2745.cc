      #include <cstdlib>
      #include <cstdio>
      #include <cstring>

      const int NMAX = 62;
      const int KMAX = 5;
      long long mm[NMAX+1][KMAX+1][KMAX+1];

      int main()
      {
        int N, K, t, p, i, j, k, jj, kk;
        while(scanf("%d %d", &N, &K) != EOF) {
          memset(mm, 0, sizeof(mm));
          mm[1][1][0] = mm[1][0][1] = 1;
          for(i = 1; i < N; i++) {
            t = i < K ? i : K;
            p = i + 1 < K ? i + 1 : K;

            for(j = 0; j <= t; j++) {
              for (k = 0; k <= t; k++) {
                jj = j + 1;
                kk = k > 0 ? k - 1 : 0;
                if (jj <= p)
                  mm[i+1][jj][kk] += mm[i][j][k];

                jj = j > 0 ? j - 1 : 0;
                kk = k + 1;
                if (kk <= p)
                  mm[i+1][jj][kk] += mm[i][j][k];
              }
            }
          }

          long long ans = 0;
          for(j = 0; j <= K; j++)
           for(k = 0; k <= K; k++)
             ans += mm[N][j][k];
          printf("%lld\n", ans);
        }
      }
