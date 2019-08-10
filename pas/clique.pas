var
        f:array[1..600,1..600] of boolean;
        a,x:array[1..600] of longint;
        dd:array[1..600] of boolean;
        kt:boolean;
        n,m,k,i,j,d,y,t,tmp:longint;
procedure result;
var     i,j:longint;
begin
        for i:=1 to k do
                write(a[x[i]],' ');
        writeln;
end;
procedure result2;
var     i,j:longint;
begin
        for i:=1 to k-1 do
                for j:=i+1 to k do
                        if not(f[a[x[i]],a[x[j]]]) then
                                exit;
        kt:=true;
        for i:=1 to k do
                write(a[x[i]],' ');
        writeln;
end;
procedure try2(i,h:longint);
var     j:longint;
begin
        if kt then exit;
        for j:=h to d do
        if dd[j] then
        begin
                if kt then exit;
                x[i]:=j;
                dd[j]:=false;
                if i=k then result2
                else try2(i+1,j+1);
                dd[j]:=true;
        end;
end;
procedure try(i,h:longint);
var
        j,t:longint;
        check:boolean;
begin
        if kt then exit;
        for j:=h to d do
        if dd[j] then
        begin
                if kt then exit;
                check:=true;
                for t:=1 to i-1 do
                        if not(f[a[j],a[x[t]]]) then
                        begin
                                check:=false;
                                break;
                        end;
                if check=true then
                begin
                x[i]:=j;
                dd[j]:=false;
                if i=k then
                begin
                        kt:=true;
                        result;
                        exit;
                end
                else try(i+1,j+1);
                dd[j]:=true;
                end;
        end;
end;
procedure nhap;
begin
        readln(t);
        while t>0 do
        begin
                dec(t);
                readln(n,m,k);
                fillchar(f,sizeof(f),false);
                for i:=1 to m do
                begin
                        read(tmp,y);
                        f[tmp,y]:=true;
                        f[y,tmp]:=true;
                end;
                for i:=1 to n do
                        f[i,i]:=true;
                d:=0;
                for i:=1 to n do
                begin
                        tmp:=0;
                        for j:=1 to n do
                        begin
                                if f[i,j] then inc(tmp);
                                if tmp=k then
                                begin
                                        inc(d);
                                        a[d]:=i;
                                        break;
                                end;
                        end;
                end;
                if d<k then writeln(-1)
                else begin
                        fillchar(dd,d,true);
                        kt:=false;
                        if n<=60 then
                        begin
                                try(1,1);
                                if kt=false then writeln(-1);
                        end
                        else
                        begin
                                try2(1,1);
                                if kt=false then writeln(-1);
                        end;
                end;
        end;
end;
begin
        assign(input,'clique.inp');
        assign(output,'clique.out');
        reset(input);
        rewrite(output);
        nhap;
        close(input);
        close(output);
end.
