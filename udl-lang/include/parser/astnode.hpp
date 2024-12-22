#ifndef _UDL_ASTNODE_
#define _UDL_ASTNODE_

#include "cleverptr/unique.hpp"
#include "nid.hpp"
#include "polysa.hpp"
#include <vector>

namespace udl {

struct Node {
  __poly_set_class_id(-1);
};

using NodePtr = cleverptr::unique_ptr<Node>;

struct Expr final : Node {
  __poly_set_class_id(Nid::expr);
  std::vector<NodePtr> children;
};

struct Stmt final : Node {
  __poly_set_class_id(Nid::stmt);
  std::vector<NodePtr> children;
};

struct VarDecl final : Node {
  __poly_set_class_id(Nid::var_decl);
  std::vector<NodePtr> children;
};

struct TypeDecl final : Node {
  __poly_set_class_id(Nid::type_decl);
  std::vector<NodePtr> children;
};

struct TypeVal final : Node {
  __poly_set_class_id(Nid::type_val);
};

struct VarVal final : Node {
  __poly_set_class_id(Nid::var_val);
};

}  // namespace udl

#endif  // _UDL_ASTNODE_
