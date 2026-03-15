#include "bst.hpp"




Tree::Tree() : root(nullptr) {}

void Tree::insert(std::string val) {
    if (root) {
        root->insert_node(new node(std::move(val)));
    }
    else {
        root = new node(std::move(val));
    }
}

Tree::node::node(std::string v) : val(std::move(v)), parent(nullptr), left(nullptr), right(nullptr) {}

void Tree::node::insert_node(node* n) {
    if (n->val < val) {
        if (left) {
            left->insert_node(n);
        }
        else {
            left = n;
            left->parent = this;
        }
    }
    else if (val < n->val) {
        if (right) {
            right->insert_node(n);
        }
        else {
            right = n;
            right->parent = this;
        }
    }
    else {
        delete n;
    }
}

bool Tree::find(const std::string& s) const{
    node* n = root;

    while(n){
        if(s == n->val){return true;}
        else if(s < n->val){n = n->left;}
        else{ n = n->right;}
    }
    return false;
}

void Tree::swap(Tree& t){
    std::swap(this->root,t.root);
}

void swap(Tree& t1, Tree& t2){
    t1.swap(t2);
}

void Tree::delete_nodes_below(node* n){
    if (!n){return;}
    delete_nodes_below(n->left);
    delete_nodes_below(n->right);
    delete n;
}

Tree::~Tree(){
    delete_nodes_below(root);
}



Tree::Tree(Tree&& other) : Tree() {
    swap(other);
}
Tree& Tree::operator=(Tree other) {
    swap(other);
    return *this;
}

Tree::iterator::iterator(const Tree* t, node* n){
    container = t;
    curr = n;
}

const std::string& Tree::iterator::operator*() const{
    if(curr){
        return curr->val;
    }   
}

bool operator!=(const Tree::iterator& it1, const Tree::iterator& it2){
    return it1.curr != it2.curr;
}

Tree::iterator& Tree::iterator::operator++(){
    if(!curr){
        return *this;
    }

    if(curr->right){
        curr = curr->right;
        while(curr->left){
            curr = curr->left;
        }
    }
    else{
        node* p = curr->parent;
        while(p && curr == p->right){
            curr = p;
            p = p->parent;
        }
        curr = p;
    }
    return *this;
}

Tree::iterator Tree::iterator::operator++(int){
    iterator temp = *this;
    ++(*this);
    return temp;
}

Tree::iterator& Tree::iterator::operator--(){
    if(!curr){
        curr = container->root->far_right();
        return *this;
    }

    if(curr->left){
        curr = curr->left;
        while(curr->right){
            curr = curr->right;
        }
    }
    else{
        node* p = curr->parent;
        while(p && curr == p->left){
            curr = p;
            p = p->parent;
        }
        curr = p;
    }
    return *this;
}

Tree::iterator Tree::iterator::operator--(int){
    iterator temp = *this;
    --(*this);
    return temp;
}

void Tree::insert_nodes_below(node* n) {
    if (n) {
        insert(n->val);
        if (n->left)  { insert_nodes_below(n->left);  }
        if (n->right) { insert_nodes_below(n->right); }
    }
}








Tree::Tree(const Tree& other) : Tree() { insert_nodes_below(other.root); }


const std::string* Tree::iterator::operator->() const {
    return &(curr->val);
}




Tree::node* Tree::node::far_left() {
    node* n = this;

    while (n->left) {
        n = n->left;
    }
    return n;
}



Tree::node* Tree::node::far_right(){
    node* n = this;
    while(n->right){
        n = n->right;
    }
    return n;
}





Tree::iterator Tree::begin() const {
    if (root) {
        return iterator(this, root->far_left());
    }
    return iterator(this, nullptr);
}
Tree::iterator Tree::end() const {
    return iterator(this, nullptr);
}




// Tree::iterator& Tree::iterator::operator++() {
//     if (!container) {
//         return *this;
//     }

//     if (!curr) {
//         if (container->root) {
//             curr = container->root->far_left();
//         }
//         return *this;
//     }

//     if(curr->right){
//         curr = curr->right;
//         while(curr->left){
//             curr = curr->left;
//         }
//     }
//     else{
//         while(curr->parent && curr == curr->parent->right){
//             curr = curr->parent;
//         }
//         curr = curr->parent;
//     }















//     return *this;
// }

// Tree::iterator& Tree::iterator::operator--() {
//     if (!container) {
//         return *this;
//     }

//     if (!curr) {
//         if (container->root) {
//             curr = container->root->far_right();
//         }
//         return *this;
//     }


//     if(curr->left){
//         curr = curr->left;
//         while(curr->right){
//             curr = curr->right;
//         }
//     }
//     else{
//         while(curr->parent && curr == curr->parent->left){
//             curr = curr->parent;
//         }
//         curr = curr->parent;
//     }













//     return *this;
// }




void Tree::erase(iterator it) {
    if (!it.curr || (it.container != this)) {
        return;
    }

    if (it.curr->left) {
        // it.curr->val = std::move(it.curr->left->far_right()->val);
        erase(--it);
        return;
    }
    if (it.curr->right) {
        it.curr->val = std::move(it.curr->right->far_left()->val);
        erase(++it);
        return;
    }
    if (it.curr == root) {
        delete root; root = nullptr;
        return;
    }

    if (it.curr->parent->left == it.curr) {
        it.curr->parent->left = nullptr;
    }
    else {
        it.curr->parent->right = nullptr;
    }
    delete it.curr;
}
