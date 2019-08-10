var
        s:array[1..3001] of string;
        t:array[0..3001] of longint;
        a:array[1..2] of string;
        kq:ansistring;
      {  dd:array['00000000000000000000'..'11111111111111111111') }
        kt:boolean;
        n,i,k,d:longint;
procedure nhap;
begin
        readln(n,k);
        a[1]:='(';a[2]:=')';
end;
procedure try(i:longint);
var     j:longint;
begin
        if kt then exit;
        for j:=1 to 2 do
        begin
                s[i]:=a[j];
                if j=1 then
                begin
                if s[i]=a[1] then t[i]:=t[i-1]+1;

                if s[i]=a[2] then t[i]:=t[i-1]-1;
                end;
                if (j=2) and (i<6) then
                begin
                if s[i]=a[1] then t[i]:=t[i+1]+1;

                if s[i]=a[2] then t[i]:=t[i+1]-1;
                end;
                 if (j=2) and (i=6) then
                begin
                if s[i]=a[1] then t[i]:=t[i-1]+1;

                if s[i]=a[2] then t[i]:=t[i-1]-1;
                end;
                if t[i]<0 then exit;
                if (i=n) then
                begin
                        if t[i]=0 then
                        begin
                        inc(d);
                        if d=k then
                        begin
                                for i:=1 to n do
                                        kq:=kq+s[i];
                                        kt:=true;
                        end;
                        end;
                end
                else try(i+1);
        end;
end;

begin
        assign(input,'bracket.inp');
        assign(output,'bracket.out');
        reset(input);
        rewrite(output);
        nhap;
        t[0]:=0;
        d:=0;kt:=false;
        kq:='';
        try(1);
        write(kq);
        close(input);
        close(output);
end.
