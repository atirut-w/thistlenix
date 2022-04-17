.proc print
    lda $200, x
    cmp #0
    beq end
    sta $e003
    inx
    jmp print
end:
    rts
.endproc
