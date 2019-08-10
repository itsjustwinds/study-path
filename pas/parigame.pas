var
        a,s:array[0..500,0..500] of longint;
        f:array[0..500,0..500] of boolean;
        i,j,n,k:longint;
procedure xuly;
var     kt1,kt2:boolean;
begin
        fillchar(s,sizeof(s),0);
        s[1,1]:=a[1,1];
        for i:=1 to n do
                for j:=1 to n do
                        s[i,j]:=s[i-1,j]+s[i,j-1]+a[i,j]-s[i-1,j-1];
        for i:=1 to n do
        begin
                if s[i,1] mod 2=0 then f[i,1]:=true
                else f[i,1]:=false;
                if s[1,i] mod 2=0 then f[1,i]:=true
                else f[1,i]:=false;
        end;
        for i:=2 to n do
                for j:=2 to n do
                begin
                        if ((s[i,j]-s[i,j-1]) mod 2=0) and (f[i,j-1]=false) then kt1:=true
                        else kt1:=false;
                        if ((s[i,j]-s[i-1,j]) mod 2=0) and (f[i-1,j]=false) then kt2:=true
                        else kt2:=false;
                        f[i,j]:=kt1 or kt2;
                end;
        if f[n,n]=true then writeln('YES')
        else writeln('NO');
end;
procedure nhap;
begin
        readln(k);
        while k>0 do
        begin
                dec(k);
                readln(n);
                for i:=1 to n do
                        for j:=1 to n do
                                read(a[i,j]);
                xuly;
        end;
end;
begin
        {assign(input,'parigame.inp');
        assign(output,'parigame.out');
        reset(input);
        rewrite(output);  }
        nhap;
        {close(input);
        close(output); }
end.