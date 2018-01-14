using System;

namespace _6task
{
    class BinTree
    {
        class treenode
        {
            public int data;
            public treenode left;
            public treenode right;
        }        
        private treenode _root;
        private void add(ref treenode tree, int data)
        {
            if (tree == null)
            {
                tree = new treenode();
                tree.data = data;
                tree.left = null;
                tree.right = null;
            }
            else if (count(tree.left) > count(tree.right))
            {
                add(ref tree.right, data);
            }
            else if (count(tree.left) <= count(tree.right))
            {
                add(ref tree.left, data);
            }
        }
        private void print(treenode tree, int level)
        {
            if (tree != null)
            {
                print(tree.right, level + 1);
                for (int i = 0; i < level; i++) Console.Write("     ");
                Console.WriteLine(tree.data);
                print(tree.left, level + 1);
            }
        }
        private int count(treenode tree)
        {
            if (tree != null)
            {
                if (tree.left == null & tree.right == null)
                {
                    return 1;
                }
                if (tree.left != null & tree.right == null)
                {
                    return count(tree.left) + 1;
                }
                if (tree.left == null & tree.right != null)
                {
                    return count(tree.right) + 1;
                }
                if (tree.left != null & tree.right != null)
                {
                    return count(tree.left) + count(tree.right) + 1;
                };
            }            
            return 0;
        }
        private int level(treenode tree)
        {
            if (tree != null)
            {
                if (tree.left == null & tree.right == null)
                {
                    return 1;
                }
                if (tree.left != null & tree.right == null)
                {
                    return level(tree.left) + 1;
                }
                if (tree.left == null & tree.right != null)
                {
                    return level(tree.right) + 1;
                }
                if (tree.left != null & tree.right != null)
                {
                    if (level(tree.left)>=level(tree.right))
                    {
                        return level(tree.left) + 1;
                    }
                    else
                    {
                        return level(tree.right) + 1;
                    }
                    
                };
            }
            return 0;
        }
        private void delete(ref treenode tree,int data)
        {
            if (tree != null)
            {
                if (tree.data == data)
                {
                    tree=null;
                }
                else
                {
                    delete(ref tree.left, data);
                    delete(ref tree.right, data);
                }
            }
        }
        private treenode get(treenode tree,int data)
        {
            treenode tmp = null;
            if (tree != null)
            {
                if (tree.data==data)
                {
                    return tree;
                }
                else
                {
                    tmp = get(tree.left, data);
                    if (tmp==null)
                    {
                        tmp = get(tree.right, data);
                    }
                    return tmp;
                }
            }
            return null;
        }
        private void toArray(treenode tree,ref int[] out_array,int i)
        {
            if (tree!=null)
                out_array[i] = tree.data;
            if (tree.left != null)
                toArray(tree.left, ref out_array, i * 2 + 1);
            if (tree.right!=null)
                toArray(tree.right, ref out_array, i * 2 + 2);
        }
        public BinTree()
        {
            _root = null;
        }        
        public void Delete(int data)
        {
            delete(ref _root, data);
        }
        public int[] ToArray()
        {
            if (_root != null)
            {
                int[] out_array = new int[(int)Math.Pow(2,level(_root))-1];
                toArray(_root, ref out_array, 0);
                return out_array;
            }
            return null;
        }
        public void Add(int data)
        {
            add(ref _root, data);
        }
        public void Print()
        {
            Console.WriteLine(count(_root));
            Console.WriteLine(level(_root));
            print(_root,0);
        }
    }
}
