/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
// class User
// {
// public:
//     // My solution
//     User(int userId)
//     {
//         user_id = userId;
//     }

//     // user id
//     int user_id;
//     // followings - unordered_set
//     // followers - unordered_set
//     unordered_set<int> followers;
//     unordered_set<int> followings;

//     // feed priority queue max heap=> time, tweet
//     priority_queue<pair<int, int>> feed;
// };

// class Twitter
// {
// public:
//     int time;
//     unordered_map<int, User *> users;
//     Twitter()
//     {
//         time = 0;
//     }

//     void postTweet(int userId, int tweetId)
//     {
//         User *curr;
//         if (users.find(userId) != users.end())
//         {
//             curr = users[userId];
//         }
//         else
//         {
//             curr = new User(userId);
//             users[userId] = curr;
//         }

//         curr->feed.push({time++, tweetId});
//     }

//     vector<int> getNewsFeed(int userId)
//     {
//         vector<int> feed;

//         if (users.find(userId) == users.end())
//             return feed;

//         priority_queue<pair<int, int>> copy_pq = users[userId]->feed;

//         for (const int &following : users[userId]->followings)
//         {
//             priority_queue<pair<int, int>> follow_feed = users[following]->feed;

//             while (!follow_feed.empty())
//             {
//                 copy_pq.push(follow_feed.top());
//                 follow_feed.pop();
//             }
//         }

//         int count = 0;

//         while (count < 10 && !copy_pq.empty())
//         {
//             feed.push_back(copy_pq.top().second);
//             copy_pq.pop();
//             count++;
//         }

//         return feed;
//     }

//     void follow(int followerId, int followeeId)
//     {
//         if (users.find(followeeId) == users.end())
//         {
//             users[followeeId] = new User(followeeId);
//         }
//         if (users.find(followerId) == users.end())
//         {
//             users[followerId] = new User(followerId);
//         }
//         users[followeeId]->followers.insert(followerId);

//         users[followerId]->followings.insert(followeeId);
//     }

//     void unfollow(int followerId, int followeeId)
//     {
//         users[followeeId]->followers.erase(followerId);
//         users[followerId]->followings.erase(followeeId);
//     }
// };

/*
    Design Twitter: post tweets, follow/unfollow, see recent tweets
    Maintain user -> tweet pairs & hash map {user -> ppl they follow}
    Time: O(n)
    Space: O(n)
*/

// Neetcode solution
class Twitter
{
public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        posts.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        // 10 tweets
        int count = 10;
        vector<int> result;

        // since postTweet pushes to the back, looping from back gets most recent
        for (int i = posts.size() - 1; i >= 0; i--)
        {
            if (count == 0)
            {
                break;
            }

            int followingId = posts[i].first;
            int tweetId = posts[i].second;
            unordered_set<int> following = followMap[userId];
            // add to result if they're following them or it's a tweet from themself
            if (following.find(followingId) != following.end() || followingId == userId)
            {
                result.push_back(tweetId);
                count--;
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId)
    {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followMap[followerId].erase(followeeId);
    }

private:
    // pairs: [user, tweet]
    vector<pair<int, int>> posts;
    // hash map: {user -> people they follow}
    unordered_map<int, unordered_set<int>> followMap;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
