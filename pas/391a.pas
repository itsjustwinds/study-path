var
        s:ansistring;
        k:string;
        i,j,res,n:longint;
        kt:boolean;
procedure nhap;
begin
        readln(s);
        k:='Bulbbasaur';
        kt:=true;
        repeat
        for i:=1 to length(k) do
        if pos(k[i],s)<>0 then
        begin
                delete(s,pos(k[i],s),1);
                if i=length(k) then inc(res);
        end
        else
        begin
                kt:=false;
                break;
        end;
        until kt=false;
        writeln(res);
end;
begin
        {assign(input,'391a.inp');
        assign(output,'391a.out');
        reset(input);
        rewrite(output);}
        nhap;
        {close(input);
        close(output);}
end.
