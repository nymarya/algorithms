-- Formalize em LEAN  os axiomas para a Teoria de Grupos.
variables (α : Type)
variables (a b c e : α )

-- relation
variable p: α → α → α

local infix `+` := p

-- axioms
axiom closure: ∀ x y : α,  ∃ c : α , ( a + b  = c )

axiom ass : ∀ a b c : α ,  (a + ( b +  c) = ( a + b) +  c) 

axiom group_id : ∃ e : α , ∀ x : α, (e + x = x ∧  x = x + e)

axiom inv : ∀ x : α, ∃ b : α , (a + b = e ∧  e = b + a)
