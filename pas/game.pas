const
        fi='game.inp';
        fo='game.out';
var
        a,l,b:array[0..1001,0..1001] of longint;
        n,m,i,j,k,kqmax,kqmin:longint;
        f:text;
procedure nhap;
begin
        assign(f,fi);
        reset(f);
        readln(f,n,m);
        readln(f,k);
        for i:=1 to n do
                for j:=1 to m do
                        read(f,a[i,j]);
        close(f);
end;
function max(a,b,c:longint):longint;
begin
        if a>b then max:=a
        else max:=b;
        if max<c then max:=c;
end;
function min(a,b,c:longint):longint;
begin
        if a<b then min:=a
        else min:=b;
        if c<min then min:=c;
end;
procedure xuly;
begin
        assign(f,fo);
        rewrite(f);
        for j:=1 to m do
        begin
             l[1,j]:=a[1,j]+k;
             b[1,j]:=a[1,j]+k;
        end;
        for i:=2 to n do
                for j:=1 to m do
                begin
                        if a[i,j]<>0 then
                        begin
                            if (j<>1) and (j<>n)then begin
                            l[i,j]:=max(l[i-1,j-1],l[i-1,j],l[i-1,j+1])+a[i,j];
                            b[i,j]:=min(b[i-1,j-1],b[i-1,j],b[i-1,j+1])+a[i,j];
                            end;
                            if (j=1) or (j=n) then begin
                            if j=1 then begin
                            l[i,j]:=max(-maxlongint,l[i-1,j],l[i-1,j+1])+a[i,j];
                            b[i,j]:=min(maxlongint,b[i-1,j],b[i-1,j+1])+a[i,j];
                            end;
                            if j=n then begin
                            l[i,j]:=max(l[i-1,j-1],l[i-1,j],-maxlongint)+a[i,j];
                            b[i,j]:=min(l[i-1,j-1],b[i-1,j],maxlongint)+a[i,j];
                            end;
                            end;
                        end
                        else begin
                                if (j<>1) and (j<>n)then begin
                                l[i,j]:=max(l[i-1,j-1],l[i-1,j],l[i-1,j+1]) div 2;
                            b[i,j]:=min(b[i-1,j-1],b[i-1,j],b[i-1,j+1]) div 2;
                            if max(l[i-1,j-1],l[i-1,j],l[i-1,j+1]) mod 2<>0 then inc(l[i,j]);
                            if min(b[i-1,j-1],b[i-1,j],b[i-1,j+1]) mod 2<>0 then inc(b[i,j]);
                                end;
                                if (j=1) or (j=n) then begin
                            if j=1 then begin
                            l[i,j]:=max(-maxlongint,l[i-1,j],l[i-1,j+1])div 2;
                            b[i,j]:=min(maxlongint,b[i-1,j],b[i-1,j+1])div 2;
                            if max(-maxlongint,l[i-1,j],l[i-1,j+1]) mod 2<>0 then inc(l[i,j]);
                            if min(maxlongint,b[i-1,j],b[i-1,j+1]) mod 2<>0 then inc(b[i,j]);
                            end;
                            if j=n then begin
                            l[i,j]:=max(l[i-1,j-1],l[i-1,j],-maxlongint)div 2;
                            b[i,j]:=min(l[i-1,j-1],b[i-1,j],maxlongint)div 2;
                            if max(l[i-1,j-1],l[i-1,j],-maxlongint) mod 2<>0 then inc(l[i,j]);
                            if min(b[i-1,j-1],b[i-1,j],maxlongint) mod 2<>0 then inc(b[i,j]);
                            end;
                            end;
                        end;
                end;
        kqmax:=l[n,1];
        kqmin:=b[n,1];
        for j:=2 to m do
        begin
                if l[n,j]>kqmax then kqmax:=l[n,j];
                if b[n,j]<kqmin then kqmin:=b[n,j];
        end;
        writeln(f,kqmin);
        writeln(f,kqmax);
        for i:=1 to n do
        begin
        for j:=1 to m do
                write(f,b[i,j],' ');
                writeln(f);
        end;
        close(f);
end;
begin
        nhap;
        xuly;
end.
