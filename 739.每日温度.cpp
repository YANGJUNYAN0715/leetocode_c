/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        // 递增栈
        stack<int> st;
        vector<int> result(T.size(), 0);
        st.push(0);
        for (int i = 1; i < T.size(); i++)
        {
            if (T[i] < T[st.top()])
            { // 情况一
                st.push(i);
            }
            else if (T[i] == T[st.top()])
            { // 情况二
                st.push(i);
            }
            else
            {
                while (!st.empty() && T[i] > T[st.top()])
                { // 情况三
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};
// @lc code=end
