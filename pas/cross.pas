var
        a:array[1..10000] of longint;
        m,i,j,n,max,vt,qve:longint;
        s:ansistring;
        res:int64;
procedure nhap;
begin
        readln(n,m);
        max:=0;
        for i:=1 to n do
        begin
                read(a[i]);
                if a[i]>max then
                begin
                        max:=a[i];
                        vt:=i;
                end;
        end;
        readln;
        for i:=vt to n-1 do
                a[i]:=a[i+1];
        readln(s);
end;
procedure xuly;
begin
        vt:=m+1;
        qve:=0;
        res:=0;
        while vt>0 do
        begin
                if (vt-max<=0)or (s[vt-max]='0') then
                begin
                        vt:=vt-max;
                        inc(qve);
                end
                else for i:=1 to max do
                        if s[vt-max-i]='0' then
                        begin
                                vt:=vt-max-i;
                                inc(qve);
                                break;
                        end;
        end;
        for i:=1 to n-1 do
                if a[i]<>0 then
                begin
                        vt:=0;
                        while vt<m+1 do
                        begin
                                if (vt+a[i]>=m+1) or (s[vt+a[i]]='0') then
                                begin
                                        vt:=vt+a[i];
                                        inc(res);
                                end
                                else for j:=1 to a[i] do
                                        if s[vt+a[i]-j]='0' then
                                        begin
                                                vt:=vt+a[i]-j;
                                                inc(res);
                                                break;
                                        end;
                        end;
                        if i<n-1 then res:=res+qve;
                end;
        writeln(res);
end;
begin
        {assign(input,'cross.inp');
        assign(output,'cross.out');
        reset(input);
        rewrite(output);}
        nhap;
        xuly;
        {close(input);
        close(output);}
end.
