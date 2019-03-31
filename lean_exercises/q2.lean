open group
open tactic

-- books
-- https://leanprover.github.io/logic_and_proof/logic_and_proof.pdf
-- https://leanprover.github.io/theorem_proving_in_lean/inductive_types.html


#print group

universe u
variables {α : Type u}

-- https://proofwiki.org/wiki/Definition:Abelian_Group
class abelian (α : Type u ) extends group α  :=
(mul_comm: ∀ a b: α , a * b = b * a  )

#print abelian

-- theorem 01
theorem letter_a [abelian α] {a b c : α} : a * (b * c) = a * (c*b) := 
sorry

-- theorem 02
theorem letter_b [abelian α] {a b c : α} : ¬∃ y a * (b * c) = a * (c*b) := 
sorry

-- theorem 01
theorem letter_c [abelian α] {a b c : α} : a * (b * c) = a * (c*b) := 
sorry
