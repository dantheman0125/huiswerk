using System;
using System.Collections.Generic;
using System.Text;

namespace OOP_Opdracht_week_1
{
    class Posts
    {
        private List<string> Tags;
        private string title, story, username;


        public Posts(string title, string story, string username)
        {
            this.title = title;
            this.story = story;
            this.username = username;
        }

        public string GetTitle()
        {
            return title;
        }

        public string GetStory()
        {
            return story;
        }

        public void SetTag(string Tag)
        {
            Tags.Add(Tag);
        }

        public string GetTags()
        {
            string tags= string.Empty;
            foreach(string Tag in Tags)
            {
                tags += Tag + ", ";
            }

            tags = tags.Remove(tags.Length - 2);
            return tags;
        }
    }
}
