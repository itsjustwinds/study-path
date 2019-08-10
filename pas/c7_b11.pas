var
        a:array [1..1000000] of string;
        i,dem,max:longint;
        s:string;
begin   dem:=0;max:=0;
        readln(s);
        s:=s+' ';
        while pos(' ',s)<>0 do
        begin
        inc(dem);
        a[dem]:=copy(s,1,pos(' ',s));
        delete(s,1,pos(' ',s));
        end;
        for i:=1 to dem do if length(a[i])>max then max:=length(a[i]);
        for i:=1 to dem do if length(a[i])=max then writeln(a[i]);
        write('do dai:',max-1);
        readln
end.
