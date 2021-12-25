#pragma once
#include <Dark.h>
#include <btBulletDynamicsCommon.h>

namespace Dark
{

  class EditorLayer : public Layer
  {
  public:
    EditorLayer();
    virtual ~EditorLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnUpdate(Timestep timestep) override;
    virtual void OnEvent(Event& event) override;

    virtual void OnImGuiRender() override;

  private:
    glm::vec3 m_SquarPosition2 = { 0.0f, 0.0f, 0.0f };

    Ref<VertexArray> m_VertexArray;

    ShaderLibrary  m_ShaderLibrary;
    Ref<Texture2D> m_Texture;
    Ref<Texture2D> m_TextureBlend;
    Ref<Texture2D> m_DfaultTex;

    OrthographicCameraController m_CameraController;

    glm::vec4 m_SquareColor = { 0.7f, 0.1f, 0.1f, 0.7f };

    Ref<Framebuffer> m_Framebuffer;

    glm::vec2 m_ViewportSize = { 0.0f, 0.0f };

    // NOTE: for bullet3 physics engine tests
    Scope<btDefaultCollisionConfiguration> m_collisionConfiguration;

    /// use the default collision dispatcher. For parallel processing you can use a diffent dispatcher (see Extras/BulletMultiThreaded)
    Scope<btCollisionDispatcher> m_dispatcher;

    Scope<btDbvtBroadphase> m_broadphase;

    /// the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
    Scope<btSequentialImpulseConstraintSolver> m_solver;

    Scope<btDiscreteDynamicsWorld> m_dynamicsWorld;

    std::vector<Ref<btCollisionShape>> m_collisionShapes;

    std::vector<Ref<btRigidBody>> m_rigidbodies;

    Ref<btRigidBody> CreateRigidBody(float mass, const btTransform& startTransform, Ref<btCollisionShape> shape, const btVector4& color = btVector4(1, 0, 0, 1));
  };

}  // namespace Dark
