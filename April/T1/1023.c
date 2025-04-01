#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    char** queries;
    int queriesSize;
    char* pattern;
    bool* results;
} CamelMatcher;

bool isLowerCase(char c) {
    return c >= 'a' && c <= 'z';
}

bool isUpperCase(char c) {
    return c >= 'A' && c <= 'Z';
}

bool matchesPattern(char* query, char* pattern) {
    int queryLen = strlen(query);
    int patternLen = strlen(pattern);
    
    int queryIdx = 0;
    int patternIdx = 0;
    
    while (queryIdx < queryLen) {
        if (patternIdx < patternLen && query[queryIdx] == pattern[patternIdx]) {
            queryIdx++;
            patternIdx++;
        } else if (isLowerCase(query[queryIdx])) {
            queryIdx++;
        } else {
            return false;
        }
    }
    
    return patternIdx == patternLen;
}

bool* camelMatch(char** queries, int queriesSize, char* pattern, int* returnSize) {
    CamelMatcher matcher;
    matcher.queries = queries;
    matcher.queriesSize = queriesSize;
    matcher.pattern = pattern;
    matcher.results = (bool*)malloc(queriesSize * sizeof(bool));
    
    *returnSize = queriesSize;
    
    for (int i = 0; i < queriesSize; i++) {
        matcher.results[i] = matchesPattern(queries[i], pattern);
    }
    
    return matcher.results;
}