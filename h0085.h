//
// Created by 项雅丽 on 2020/3/2.
//

#ifndef LEETCODE_H0085_H
#define LEETCODE_H0085_H

#include <iostream>
#include <vector>
using namespace std;

namespace h0085{
    class Solution {
    public:
        int maximalRectangle(vector<vector<char>>& matrix) {
            int m = matrix.size();
            if (m == 0) return 0;
            int n = matrix[0].size();
            vector<vector<int>>store(m,vector<int>(n, 0));
            for ( int i = 0; i < m; i++){
                store[i][0] = ( matrix[i][0] == '1')?1:0;
                for ( int j = 1; j < n; j++){
                    if (matrix[i][j] == '1')
                        store[i][j] = store[i][j-1]+1;
                    else
                        store[i][j] = 0;
                }
            }
            // for (int i= 0 ; i<m; i++){
            //     for ( int j = 0; j<n; j++){
            //         cout<<store[i][j]<<" ";
            //     }cout<<endl;
            // }
            int max_area = 0;
            for (int j = 0; j < n; j++){
                for (int start=0; start<m; start++){
                    int maxwidth = store[start][j];
                    for (int end=start; end<m; end++){
                        maxwidth = min(maxwidth, store[end][j]);
                        int h = end - start + 1;
                        max_area = max(max_area, maxwidth*h);
                    }
                }
            }

            return max_area;
        }

    };
}

#endif //LEETCODE_H0085_H
