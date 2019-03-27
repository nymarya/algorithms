open classical

variables p q r s : Prop

-- commutativity of ∧ and ∨
example : p ∧ q ↔ q ∧ p := 
iff.intro(
    assume h1: p ∧ q,
    show q ∧ p, from and.intro( and.right h1 ) ( and.left h1)
)
(
    assume h: q ∧ p,
    show p ∧ q, from and.intro( and.right h)(and.left h)
) --end proof

example : p ∨ q ↔ q ∨ p := 
iff.intro(
    assume h: p ∨ q,
    or.elim h (λ hp, or.inr hp) (λ hq, or.inl hq)
     -- proof p ∨ q → q ∨ p
) 
(
assume h: q ∨ p,
    or.elim h (λ hq, or.inr hq) (λ hq, or.inl hq)
     -- proof q ∨ p → p ∨ q
)

-- associativity of ∧ and ∨
example : (p ∧ q) ∧ r ↔ p ∧ (q ∧ r) := 
iff.intro(
    assume h: (p ∧ q) ∧ r,
    and.intro ( h.left.left ) ( and.intro (h.left.right) (h.right))
)
(
    assume h: p ∧ (q ∧ r),
    and.intro ( and.intro (h.left) (h.right.left) ) ( h.right.right)
) -- end proof

example : (p ∨ q) ∨ r ↔ p ∨ (q ∨ r) := sorry

-- distributivity
example : p ∧ (q ∨ r) ↔ (p ∧ q) ∨ (p ∧ r) := sorry
example : p ∨ (q ∧ r) ↔ (p ∨ q) ∧ (p ∨ r) := sorry

-- other properties
example : (p → (q → r)) ↔ (p ∧ q → r) := sorry
example : ((p ∨ q) → r) ↔ (p → r) ∧ (q → r) := sorry
example : ¬(p ∨ q) ↔ ¬p ∧ ¬q := sorry
example : ¬p ∨ ¬q → ¬(p ∧ q) := sorry
example : ¬(p ∧ ¬p) := sorry
example : p ∧ ¬q → ¬(p → q) := sorry
example : ¬p → (p → q) := sorry
example : (¬p ∨ q) → (p → q) := sorry
example : p ∨ false ↔ p := sorry
example : p ∧ false ↔ false := sorry
example : ¬(p ↔ ¬p) := sorry
example : (p → q) → (¬q → ¬p) := sorry

-- these require classical reasoning
example : (p → r ∨ s) → ((p → r) ∨ (p → s)) := sorry
example : ¬(p ∧ q) → ¬p ∨ ¬q := sorry
example : ¬(p → q) → p ∧ ¬q := sorry
example : (p → q) → (¬p ∨ q) := sorry
example : (¬q → ¬p) → (p → q) := sorry
example : p ∨ ¬p := sorry
example : (((p → q) → p) → p) := sorry
