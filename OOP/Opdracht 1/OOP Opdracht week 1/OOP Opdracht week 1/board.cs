using System;
using System.Collections.Generic;
using System.Text;

namespace OOP_Opdracht_week_1
{
    class board
    {
        List<Posts> posts;
        string name;

        public board (string name)
        {
            this.name = name;
        }

        public void AddPost(Posts post)
        {
            posts.Add(post);
        }

        public List<Posts> GetPosts()
        {
            return posts;
        }
    }
}