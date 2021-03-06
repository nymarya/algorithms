-- constants
variables x y z u v w :Prop

-- relations
variable B: Prop →  Prop → Prop → Prop --betweeness
variable C: Prop → Prop → Prop → Prop → Prop -- congruence

-- axioms
--- identity of betweness
axiom bet_id : B x y x → x = y
--- reflexivity of congruence
axiom cong_refl : C x y y x
--- identity of congruence
axiom cong_id : C x y z z → x = y
--- transitivity of congruence
axiom cong_trans:  (C x y z u ∧ C x y v w) →  C z u v w.

-- theorem: symmetry  of betweeness
theorem bet_sym: B x y z → B y z x :=
sorry

example: (C x y z z ↔ x = y) ↔ (B x y x) :=
iff.intro(
    assume h1: C x y z z ↔ x = y, 
    show B x y x, from sorry
) --end iff.intro
(
    assume h2: B x y x,
    show  C x y z z ↔ x = y, from sorry

)

--https://en.wikipedia.org/wiki/Tarski%27s_axioms
