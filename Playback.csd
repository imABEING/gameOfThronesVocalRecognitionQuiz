<CsoundSynthesizer>
<CsInstruments>
instr testing
 a1 diskin2 "OberynMartell.aif", p5
 k1 linen 1, .2, p3, .3
 out a1 * k1
endin
</CsInstruments>
<CsScore>
i "testing" 0 7.2 0 1 
e 7.7
</CsScore>
</CsoundSynthesizer>
