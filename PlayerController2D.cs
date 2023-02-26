using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController : MonoBehaviour
{
    // 2D basic player controller 
    // by: IcyIme
    // Time: 1:41 26.2.2023
    // This is only demo code, it will still be completed

    [SerializeField]
    private float _speedPower = 250f, // Default player speed
                  _jumpPower = 15f; // Default jump power (Rigid GravityScale: 5)

    [SerializeField] private bool _isJumping;
    [SerializeField] private bool _isOnGround;

    private float _moveDirX; // For get 1 or -1 depends on user input

    private float _coyoteTime = 0.2f;
    private float _coyoteTimeCounter;

    private float _jumpBufferTime = 0.2f;
    private float _jumpBufferCounter;

    private Rigidbody2D _rigid;
    private Animator _anim;

    // Start is called before the first frame update
    private void Start()
    {
        // Getting compoments
        _rigid = GetComponent<Rigidbody2D>();
        _anim = GetComponent<Animator>();
    }

    private void FixedUpdate()
    {
        // Move magic
        _rigid.velocity = new Vector2(_moveDirX * _speedPower * Time.deltaTime, _rigid.velocity.y);
    }

    // Update is called once per frame
    private void Update()
    {
        Run();
        Jump();
    }

    #region Collision2d
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Ground"))
        {
            _isOnGround = true;
            _anim.SetBool("isJump", false);
            Debug.Log("joined");
        }
    }

    private void OnCollisionExit2D(Collision2D collision)
    {
        if (collision.gameObject.CompareTag("Ground"))
        {
            _isOnGround = false;
            _anim.SetBool("isJump", true);
            Debug.Log("left");
        }
    }
    #endregion

    #region RunFuction2D
    private void Run()
    {
        _moveDirX = Input.GetAxisRaw("Horizontal"); // only 1 or -1
        _anim.SetBool("isRun", false);

        // Setting up animation and PlayerFacing
        if (_moveDirX > 0 || _moveDirX < 0)
        {
            transform.localScale = new Vector3(_moveDirX, 1f, 1f);
            RunAnim();
        }
    }

    void RunAnim()
    {
        if (_isOnGround && !_anim.GetBool("isRun"))
            _anim.SetBool("isRun", true);

    }
    #endregion

    #region JumpFunction2D
    private void Jump()
    {
        // Grace period where you can still jump after falling off
        if (_isOnGround)
        {
            _coyoteTimeCounter = _coyoteTime;
        }
        else
        {
            _coyoteTimeCounter -= Time.deltaTime;
        }

        // For detect jump before fully grounded
        if (Input.GetButtonDown("Jump"))
        {
            _jumpBufferCounter = _jumpBufferTime;
        }
        else
        {
            _jumpBufferCounter -= Time.deltaTime;
        }

        // jump heigh by how long you hold jump button
        if (_coyoteTimeCounter > 0f && _jumpBufferCounter > 0f && !_isJumping)
        {
            _rigid.velocity = new Vector2(_rigid.velocity.x, _jumpPower);

            _jumpBufferCounter = 0f;

            StartCoroutine(JumpCooldown());
        }

        if (Input.GetButtonUp("Jump") && _rigid.velocity.y > 0f)
        {
            _rigid.velocity = new Vector2(_rigid.velocity.x, _rigid.velocity.y * 0.5f);

            _coyoteTimeCounter = 0f;
        }
    }
    
    //Jump cooldown
    private IEnumerator JumpCooldown()
    {
        _isJumping = true;
        yield return new WaitForSeconds(0.4f);
        _isJumping = false;
    }
    #endregion
}
