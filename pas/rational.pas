var
        q1,q2:array[1..10000000] of longint;
        s:string;
        a,x,b,i,j,l,r,vt,u1,u2:longint;
procedure nhap;
begin
        readln(s);
        vt:=pos('/',s);
        val(copy(s,1,vt-1),a,x);
        val(copy(s,vt+1,length(s)-vt),b,x);
end;
procedure xuly(i:longint);
begin
        if i=1 then
        begin
                inc(r);
                q1[r]:=u1;
                q2[r]:=u1+u2;
        end
        else begin
                inc(r);
                q1[r]:=u1+u2;
                q2[r]:=u2;
        end;
end;
procedure bfs;
begin
        l:=1;r:=1;
        q1[1]:=1;
        q2[1]:=1;
        repeat
                u1:=q1[l];
                u2:=q2[l];
                inc(l);
                for i:=1 to 2 do
                begin
                        xuly(i);
                        if (q1[r]=a)and(q2[r]=b) then
                        begin
                                writeln(r);
                                exit;
                        end;
                end;
        until l>r;
end;
begin
        assign(input,'rational.inp');
        assign(output,'rational.out');
        reset(input);
        rewrite(output);
        nhap;
        if (a=1) and (b=1) then writeln(1) else bfs;
        close(input);
        close(output);
end.
