Node* LCA(Node *p, int n1, int n2)
{
   if(!p) return NULL;
   if(p->data == n1 || p->data == n2) return p;
   if(p->data < min(n1, n2)) return LCA(p->right, n1, n2);
   if(p->data > max(n1, n2)) return LCA(p->left, n1, n2);
   return p;
}