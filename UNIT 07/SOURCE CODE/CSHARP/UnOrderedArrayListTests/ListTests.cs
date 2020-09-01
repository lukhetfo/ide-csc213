using Microsoft.VisualStudio.TestTools.UnitTesting;
using UnOrderedArrayList;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UnOrderedArrayList.Tests
{
    [TestClass()]
    public class ListTests
    {
        [TestMethod()]
        public void ListTest()
        {
            List L = new List();

            int init_size = 0;
            Assert.AreEqual(init_size, L.Size);
        }

        [TestMethod()]
        public void IsEmptyTest()
        {
            List L = new List();
            Assert.IsTrue(L.IsEmpty());
        }

        [TestMethod()]
        public void IsFullTest()
        {
            List L = new List();

            while (!(L.IsFull()))
                L.Insert(10);
            
            Assert.AreEqual(List.MaxSize, L.Size);
            Assert.IsTrue(L.IsFull());
        }

        [TestMethod()]
        public void InsertTest()
        {
            List L = new List();
            L.Insert(10); L.Insert(15); L.Insert(20);
            Assert.AreEqual(3, L.Size);
            Assert.AreEqual(20, L.Item[L.Size - 1]);     
        }

        [TestMethod()]
        public void DeleteTest()
        {
            List L = new List();
            L.Insert(10); L.Insert(15); L.Insert(20);
            Assert.AreEqual(3, L.Size);
            
            L.Delete(15);
            Assert.AreEqual(2, L.Size);
            Assert.IsFalse(L.IsEmpty());

            while (!(L.IsEmpty()))
            {
                L.Delete(L.Item[0]);
            }
            Assert.AreEqual(0, L.Size);
            Assert.IsTrue(L.IsEmpty());
        }

        [TestMethod()]
        public void ShowDataTest()
        {
            List L = new List();
            L.Insert(10); L.Insert(15); L.Insert(20);
            Assert.AreEqual(3, L.Size);
            const string Expected_Output = "10 15 20";
            using (var sw = new System.IO.StringWriter())
            {
                Console.SetOut(sw);
                L.ShowData();

                var result = sw.ToString().Trim();
                Assert.AreEqual(Expected_Output, result);
            }
        }
    }
}