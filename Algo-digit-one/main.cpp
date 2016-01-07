//
//  main.cpp
//  Algo-digit-one
//
//  Created by Chaojun Xue on 1/5/16.
//  Copyright © 2016 Chaojun Xue. All rights reserved.
//

/*
 Given an integer n, count the total number of digit 1 appearing
 in all non-negative integers less than or equal to n.
 
 For example:
 Given n = 13,
 Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 */

#include <iostream>
#include <list>
#include <vector>

class Solution {
public:
    long countDigitOne(long n) {
        
        if(n <= 0) return 0;
        
        long count = 0;
        splitNumber(n);
        
        std::pair<int, int> pr = digitals.back();
        long weight = pr.first - 1;
        long digital = pr.second;
        long sum = 0;
        
        if(weight == 0){
            count = 1;
        }
        else{
            for(int i = 1; i <= weight; i++){
                sum += C(weight, i) * power(9, weight - i)*i;
            }
            
            long q = n - digital * power(10, weight);
            
            if(digital == 1){
                count = (n - power(10, weight) + 1) + sum;//power(10, weight);
                count += countDigitOne(q);
            }
            else{
                
                count = (digital) * sum + power(10, weight) + countDigitOne(q);
            }
            
        }
        
        return count;
    }
    
    int countDigitOne1(int n) {
        int count = 0;
        
        for(int i = 1; i<=n; i++){
            int q = i;
            while(q != 0){
                int m = q % 10;
                q = q / 10;
                
                if(m == 1){
                    count++;
                    //break;
                }
            }
        }
        
        return count;
    }
    
protected:
    void splitNumber(long n){
        int weight = 1;
        while(n != 0){
            int m = n % 10;
            n = n /10;
            
            if(m != 0){
                std::pair<int, int> p = std::make_pair(weight, m);
                digitals.push_back(p);
            }
            weight++;
        }
    }
    
    long C(long n, long m){
        if(m > n/2) m = n - m;
        if(m == 0) return 1;
        
        long n1 = 1;
        long n2 = 1;
        for(long i = n; i > n - m; --i){
            n1 *= i;
        }
        
        for(long j = m; j >= 2; --j){
            n2 *= j;
        }
        
        //printf("n=%d, m=%d, C=%d\n", n, m, n1/n2);
        
        return n1/n2;
    }
    
    long power(long base, long times){
        long sum = 1;
        
        for(int i=0; i < times; i++){
            sum *= base;
        }
        return sum;
    }
    
private:
    std::list<std::pair<int, int>> digitals;
    
};

int main(int argc, const char * argv[]) {
    Solution solution;
    
    int testNum = 213924211;
    
    std::cout << "Hello, World1 "<<solution.countDigitOne(testNum)<< std::endl;
    std::cout << "Hello, World2 "<<solution.countDigitOne1(testNum)<< std::endl;
    return 0;
}
