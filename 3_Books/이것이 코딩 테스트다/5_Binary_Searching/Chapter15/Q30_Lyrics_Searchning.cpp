#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (int i = 0; i < queries.size(); i++)
    {
        int ret = 0;
        int q_index = -1;
        int low = 0;
        int high = queries[i].length() - 1;
        // ?가 접미사일 경우
        //c++에서는 -1로 마지막 인덱스에 접근 불가능...
        if (queries[i][queries[i].length() - 1] == '?')
        {
            // question Mark의 위치를 찾기위한 binary search
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (queries[i][mid] == '?')
                {
                    q_index = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            }
            //이후에 words의 단어들과 비교
            for (int j = 0; j < words.size(); j++)
            {
                if (queries[i].length() != words[j].length()) continue;
                bool isMatched = true;
                for (int index = 0; index < q_index; index++)
                {
                    if (queries[i][index] != words[j][index])
                    {
                        isMatched = false;
                        break;
                    }
                }
                if (isMatched) ret++;
            }
            answer.push_back(ret);
        }
        // ?가 접두사일 경우
        else
        {
            //question Mark의 위치를 찾기위한 binary search
            while (low <= high)
            {
                int mid = (low + high) / 2;
                if (queries[i][mid] == '?')
                {
                    q_index = mid;
                    low = mid + 1;
                }
                else high = mid - 1;
            }

            for (int j = 0; j < words.size(); j++)
            {
                if (queries[i].length() != words[j].length()) continue;
                bool isMatched = true;
                for (int index = q_index + 1; index < queries[i].length(); index++)
                    if (queries[i][index] != words[j][index])
                    {
                        isMatched = false;
                        break;
                    }
                if (isMatched) ret++;
            }
            answer.push_back(ret);
        }
    }

    return answer;
}