
variables ( A B C D : Prop )

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
sorry
