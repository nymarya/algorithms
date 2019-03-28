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

example : (p ∨ q) ∨ r ↔ p ∨ (q ∨ r) := 
iff.intro(
    assume h: (p ∨ q) ∨ r,
    or.elim h
    (-- begin p ∨ q -> p ∨ (q ∨ r)
        assume h1: p ∨ q,
        or.elim h1
        (
            assume hp: p,
            show p ∨ (q ∨ r), from or.inl hp  
        )
        (
            assume hq: q,
            show p ∨ (q ∨ r), from or.inr (or.inl hq)
        )
    )-- end p ∨ q -> p ∨ (q ∨ r)
    (--begin r → p ∨ (q ∨ r)
        assume hr: r,
        show p ∨ (q ∨ r), from or.inr (or.inr hr) 
    )
) --end proof (p ∨ q) ∨ r →  p ∨ (q ∨ r)
( -- begin p ∨ (q ∨ r) → (p ∨ q) ∨ r
    assume h: p ∨ (q ∨ r),
    or.elim h
    (--begin p → (p ∨ q) ∨ r
        assume hp: p,
        show (p ∨ q) ∨ r, from or.inl( or.inl hp)
    )--end p → (p ∨ q) ∨ r
    (--begin q ∨ r → (p ∨ q) ∨ r
        assume h2: q ∨ r,
        or.elim h2(
            assume hq: q,
            show (p ∨ q) ∨ r, from or.inl( or.inr hq)
        )
        (
            assume hr: r,
            show (p ∨ q) ∨ r, from or.inr hr
        )
    )
) -- end proof p ∨ (q ∨ r) → (p ∨ q) ∨ r


-- distributivity
example : p ∧ (q ∨ r) ↔ (p ∧ q) ∨ (p ∧ r) := 
iff.intro(-- begin p ∧ (q ∨ r) → (p ∧ q) ∨ (p ∧ r)
    assume h: p ∧ (q ∨ r),
    have hp: p, from h.left,
    or.elim h.right 
    ( --begin p , q  → (p ∧ q) ∨ (p ∧ r)
        assume hq: q,
        show (p ∧ q) ∨ (p ∧ r), from or.inl ⟨ hp, hq⟩ 
    )
    (--begin p , r  → (p ∧ q) ∨ (p ∧ r)
        assume hr: r,
        show (p ∧ q) ∨ (p ∧ r), from or.inr (and.intro hp hr) 
    )--end p, r → (p ∧ q) ∨ (p ∧ r)
)-- end p ∧ (q ∨ r) → (p ∧ q) ∨ (p ∧ r)
(-- begin (p ∧ q) ∨ (p ∧ r) → p ∧ (q ∨ r)
    assume h: (p ∧ q) ∨ (p ∧ r),
    or.elim h
    (-- begin (p ∧ q) → p ∧ (q ∨ r)
        assume h1: p ∧ q,
        show p ∧ (q ∨ r), from and.intro h1.left (or.inl h1.right)
    )
    (-- begin (p ∧ r) → p ∧ (q ∨ r)
        assume h1: p ∧ r,
        show p ∧ (q ∨ r), from and.intro h1.left (or.inr h1.right)
    ) 

)-- end (p ∧ q) ∨ (p ∧ r) → p ∧ (q ∨ r)

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
