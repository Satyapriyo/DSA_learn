
class node:
    def __init__(self,data):
        self.val =data
        self.right =None
        self.left =None
def insert(root,data):
    if root is None :
        return node(data)
    else:
        if root.val == data:
            return root
        elif root.val < data:
            root.right=insert(root.right,data)
        else:
            root.left=insert(root.left,data)
    return root
def inorder(root):
    if root:
        inorder(root.left)
        print(root.val ," ")
        inorder(root.right)

r=node(50)
r=insert(r,30)
r=insert(r,40)
r=insert(r,10)
r=insert(r,70)
inorder(r)
