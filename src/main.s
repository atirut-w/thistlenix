.import print
.segment "STARTUP"
    lda #<text
    jsr print
    rts

text:
    .byte "Hello World!", $0a, 0
