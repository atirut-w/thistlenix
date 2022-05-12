.segment "STARTUP"
.import kprint

.proc main
    lda #<text
    ldx #>text
    jsr kprint
    rts

text: .byte "Hello, world!", 10, 0
.endproc
