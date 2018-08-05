<CsoundSynthesizer>
<CsInstruments>
instr testing
 a1 diskin2 "NedStark.aif", p5
 k1 linen 1, .2, p3, .3
 out a1 * k1
endin
</CsInstruments>
<CsScore>
i "testing" 0 2.5 0 1 
e 3
</CsScore>
</CsoundSynthesizer>
