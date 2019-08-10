var
        g,c:longint;
begin
        for g:=1 to 35 do
        begin
        c:=36-g;
        if 2*g + 4*c=100 then
        begin
        write('so ga va cho lan luot la:',g,' ',c);
        break;
        end;
        end;
        readln
end.
