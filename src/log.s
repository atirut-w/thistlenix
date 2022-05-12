.importzp ptr1
.import incax
.export kprint

.proc kprint
    sta ptr1
    stx ptr1+1
loop:
    lda (ptr1)
    cmp #0
    beq end
    sta $e003

    lda ptr1
    jsr incax
    sta ptr1
    stx ptr1+1
    jmp loop
end:
    rts
.endproc
