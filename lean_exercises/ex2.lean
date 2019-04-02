-- Formalize em LEAN  os axiomas para a Teoria de Grupos.
variables (α : Type) (e : Type)

-- relation
variable p: α → α → Prop

infix `+`:= p

-- axioms
axiom closure: ∀x y : α, x + y : α;

axiom ass : ∀ a b c : α,  a + (b + c) = (a + b) + c;

axiom id : ∃ e : α , ∀ x : α, e + x = x = x + e;

axiom inv : ∀ x : α, ∃ b : α , a + b = e = b + a;
