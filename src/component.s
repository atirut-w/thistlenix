.ifndef _COMPONENT_S_
_COMPONENT_S_ = 1

; Component-related subroutines, mostly wrappers for the component mapper.
; See: https://github.com/gamax92/Thistle/wiki/Component-Mapper

.scope component

.proc get_count
    lda #3
    sta $e010

    ldx $e010
    ldy $e011

    rts
.endproc

.endscope

.endif
