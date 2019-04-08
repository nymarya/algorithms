-- ∀x. R(x) → S(x) ⊢ ∃y R(y)→ ∃z S(z)
open classical

variables (α : Type) (p q R S : α → Prop)
variables x y z a: α 
variable r: Prop


example (h : ∀ x, p x → q x ) :  (∃ y, p y) → (∃ z , q z) :=
assume h1: ∃ y, p y,
show (∃ z , q z), from
    exists.elim h1 
    (
        assume w: α, 
        assume hw: p w, 
        exists.intro (w) ( h(w)(hw) ) 
    )
