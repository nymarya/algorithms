variables ( A B C D P Q : Prop )

variable R: Prop → Prop

-- LCP-003
example ( h1: A→(B→C)) (h2 : A→B)  : (A→C) := 
assume h3: A,
show C, from h1 (h3) (h2 (h3))

-- LCP-007	
example ( h: A→(B→(C→D))) : (C→(B→(A→D))) := 
assume hc: C,
assume hb: B,
assume ha: A,
show D , from h (ha) (hb) (hc)

-- LCP-032	
example (h : (A ∨ B) → C) : (A -> C) :=
assume ha: A,
show C, from h (or.inl ha)

-- LCP-093	
example ( h : A ∨ B): ¬(¬A∧¬B) :=
assume h1 : ¬A∧¬B, 
show false, from 
    or.elim h (
        assume ha: A,
        absurd ha h1.left
    )
    (
        assume hb: B,
        absurd hb h1.right
    )

-- LCPO-07   
example (h : P -> ∀x,R(x)) :  ∀x,(P -> R(x)) :=
assume y,
assume P, 
show R y, from h (P) y

-- LCPO-22	
example (h: ∀x,R(x) ) : ∀y,( P ∨ R(y) ∨ Q ) :=
assume y,
show P ∨ R y ∨ Q, from or.inr ( or.inl (h y) )

-- LCPO-40	
example ( h: ∃x,R(x)) : (∃x,∃y,(R(x)∧R(y))) := 
exists.elim h
  (assume (y ) (h1 : R y),
    show ∃x, ∃y, R x ∧  R y , from 
        exists.intro y ( exists.intro y (and.intro (h1) (h1)) )
    )

-- LCPO-58	
example ( h: ¬∃x,R(x) ) : ( ∀ x,¬R(x)) := 
assume x, 
assume hp: R x,
have ∃ x, R x, from  exists.intro x hp ,
h this
