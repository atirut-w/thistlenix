.import print
.segment "STARTUP"
    lda #<text
    jsr print
    rts

text:
    .asciiz "Hello World!\n"
